#include "gtest/gtest.h"

#include <algorithm>

#include "../src/moves/Paper.h"
#include "../src/moves/Rock.h"
#include "../src/moves/Scissors.h"
#include "../src/strategies/RandomStrategy.h"

namespace roshambo_test {

using namespace game;

class Strategy_TEST : public ::testing::Test
{
protected:
    Strategy_TEST()
    {
        choices.push_back(new Paper);
        choices.push_back(new Rock);
        choices.push_back(new Scissors);
    }

    virtual ~Strategy_TEST() {}

    virtual void SetUp()
    {
        // post-construction
    }

    virtual void TearDown()
    {
        // pre-destruction
    }

    RandomStrategy random_strat;
    std::vector<Move *> choices;
};

TEST_F(Strategy_TEST, RandomStrategy)
{
    EXPECT_TRUE(std::find(choices.begin(), choices.end(), random_strat.pick(choices)) != choices.end());
}

} // namespace roshambo_test