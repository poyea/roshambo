#include "gtest/gtest.h"

#include "../src/util/Random.h"

namespace roshambo_test {

using namespace util;

class Util_TEST : public ::testing::Test
{
protected:
    Util_TEST() {}

    virtual ~Util_TEST() {}

    virtual void SetUp()
    {
        // post-construction
    }

    virtual void TearDown()
    {
        // pre-destruction
    }
};

TEST_F(Util_TEST, Random)
{
    for (std::size_t i = 100; i < 150; ++i) {
        EXPECT_TRUE(Random::rand(i) <= i);
        EXPECT_TRUE(Random::rand(i));
    }
}

} // namespace roshambo_test