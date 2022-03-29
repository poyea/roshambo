#include "gtest/gtest.h"

#include "../src/moves/Paper.h"
#include "../src/moves/Rock.h"
#include "../src/moves/Scissors.h"

namespace roshambo_test {

using namespace game;

class Moves_TEST : public ::testing::Test
{
protected:
    Moves_TEST() : rock(new Rock), paper(new Paper), scissors(new Scissors) {}

    virtual ~Moves_TEST() {}

    virtual void SetUp()
    {
        // post-construction
    }

    virtual void TearDown()
    {
        // pre-destruction
    }

    Rock *rock;
    Paper *paper;
    Scissors *scissors;
};

TEST_F(Moves_TEST, Tie)
{
    EXPECT_TRUE(rock->beats(rock) == nullptr);
    EXPECT_TRUE(paper->beats(paper) == nullptr);
    EXPECT_TRUE(scissors->beats(scissors) == nullptr);
}

TEST_F(Moves_TEST, Winning)
{
    EXPECT_TRUE(rock->beats(scissors) == rock);
    EXPECT_TRUE(scissors->beats(paper) == scissors);
    EXPECT_TRUE(paper->beats(rock) == paper);
}

TEST_F(Moves_TEST, Losing)
{
    EXPECT_TRUE(scissors->beats(rock) == rock);
    EXPECT_TRUE(paper->beats(scissors) == scissors);
    EXPECT_TRUE(rock->beats(paper) == paper);
}

} // namespace roshambo_test