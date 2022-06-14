#include <gtest/gtest.h>

TEST(ShouldSucceed, IntSize)
{
    ASSERT_EQ(sizeof(int), 4);
}

TEST(ShouldSucceed, LongLongSize)
{
    ASSERT_EQ(sizeof(long long), 8);
}

TEST(ShouldSucceed, FloatSize)
{
    ASSERT_EQ(sizeof(float), 4);
}

TEST(ShouldSucceed, LongDoubleSize)
{
    ASSERT_EQ(sizeof(double), 8);
}

#include <discpp/discpp.h>
TEST(Gateway, GatewayClient)
{
    discpp::Client client("OTU4MzcyODIwMjY4NzY1MjU3.GQuFEr.9GdlhgicTjkP8JiRgjVjHiXWtbwoqrN4YeCunM");
    client.start();
    client.send("{\"op\": 2,\"d\": {\"token\": \""
                "OTU4MzcyODIwMjY4NzY1MjU3.GQuFEr.9GdlhgicTjkP8JiRgjVjHiXWtbwoqrN4YeCunM"
                "\",\"intents\": 513,\"properties\": {\"$os\": \"linux\",\"$browser\": \"discpp\",\"$device\": \"discpp\"}}}");
}