#include <iostream>
#include <sstream>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <functional>
#include <vector>
#include <semaphore>
#include <format>

static constexpr auto k_invalidArgumentsMessage = "The only parameter must be a number of iterations.\nExample: program.exe 5";

static std::mt19937 s_rng(std::random_device{}());

enum class Component
{
    NoMoreLeft = -1,
    None = 0,
    Tobacco,
    Paper,
    Match
};

static const std::unordered_map<Component, std::string_view> s_nameToComponentMap
{
    { Component::Tobacco, "Tobacco" },
    { Component::Paper, "Paper" },
    { Component::Match, "Match" }
};

static std::binary_semaphore s_produceSemaphore(1);
static std::counting_semaphore<3> s_consumeSemaphore(0);

static std::array<Component, 2> s_componentsOnTheTable = { Component::None, Component::None };
static std::unordered_map<std::string, size_t> s_smokedCount;

void SmokerFunc(const std::string& name, Component ownComponent)
{
    s_smokedCount.emplace(name, 0);

    while (true)
    {
        s_consumeSemaphore.acquire();
        if (s_componentsOnTheTable[0] == Component::NoMoreLeft)
        {
            break;
        }

        std::unordered_set<Component> availableComponents;
        availableComponents.insert(ownComponent);
        availableComponents.insert(s_componentsOnTheTable[0]);
        availableComponents.insert(s_componentsOnTheTable[1]);
        if (!availableComponents.contains(Component::Tobacco) ||
            !availableComponents.contains(Component::Paper) ||
            !availableComponents.contains(Component::Match))
        {
            s_consumeSemaphore.release();
            continue;
        }

        std::cout << std::format("{} added {} to assemble a cigarette and smoked it\n",
            name, s_nameToComponentMap.at(ownComponent));

        s_componentsOnTheTable[0] = s_componentsOnTheTable[1] = Component::None;
        s_smokedCount[name]++;
        s_produceSemaphore.release();
    }

    std::cout << std::format("{} exited\n", name);
}

void ProducerFunc(size_t iterationsCount)
{
    while (iterationsCount--)
    {
        s_produceSemaphore.acquire();
        auto generateComponent = [] {
            return static_cast<Component>(
                std::uniform_int_distribution<int>(
                    static_cast<int>(Component::Tobacco), static_cast<int>(Component::Match))(s_rng));
        };
        s_componentsOnTheTable[0] = generateComponent();
        do
        {
            s_componentsOnTheTable[1] = generateComponent();
        } while (s_componentsOnTheTable[1] == s_componentsOnTheTable[0]);
        std::cout << std::format("The producer placed {} and {} on the table\n",
            s_nameToComponentMap.at(s_componentsOnTheTable[0]), s_nameToComponentMap.at(s_componentsOnTheTable[1]));
        s_consumeSemaphore.release();
    }

    s_produceSemaphore.acquire();
    s_componentsOnTheTable[0] = s_componentsOnTheTable[1] = Component::NoMoreLeft;
    std::cout << "The producer indicated that there are no more components left\n";
    std::cout << "The producer exited\n";
    s_consumeSemaphore.release(3);
}

void Init(size_t iterationsCount)
{
    std::thread producerThread(std::bind(ProducerFunc, iterationsCount));
    std::vector<std::thread> smokerThreads;
    size_t smokerThreadsIndex = 0;
    for (const auto [component, _] : s_nameToComponentMap)
    {
        smokerThreads.emplace_back(std::bind(SmokerFunc, std::format("Smoker-{}", ++smokerThreadsIndex), component));
    }

    producerThread.join();
    std::cout << "Producer thread has joined\n";
    for (auto& smokerThread : smokerThreads)
    {
        smokerThread.join();
    }
    std::cout << "All threads have joined\n\n";
    for (const auto [name, count] : s_smokedCount)
    {
        std::cout << std::format("{} smoked {} cigarettes\n", name, count);
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << k_invalidArgumentsMessage;
        return 1;
    }
    std::istringstream ss(argv[1]);
    int iterationsCount;
    ss >> iterationsCount;
    char buf;
    if (ss.fail() || ss.get(buf) || iterationsCount < 0)
    {
        std::cout << k_invalidArgumentsMessage;
        return 1;
    }

    Init(static_cast<size_t>(iterationsCount));
}
