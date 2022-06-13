#ifndef __DISCPP_DEFINITIONS_H__
#define __DISCPP_DEFINITIONS_H__

#define str(s) xstr(s)
#define xstr(s) #s

#define DISCORD_BASE_URL "https://discord.com/api"
#define DISCORD_VERSION 10
#define DISCORD_EP DISCORD_BASE_URL str(DISCORD_VERSION)

#define DISCORD_EPOCH 1420070400000ULL

#include <chrono>

namespace discpp
{
    struct snowflake
    {
        std::time_t timestamp : 42; // : {number} sets the size of the field in bits
        unsigned char workerId : 5;
        unsigned char processId : 5;
        unsigned short increment : 12;

        operator unsigned long long() const
        {
            return ((timestamp - DISCORD_EPOCH) << 22) |
                   (workerId & 0x1F) << 17 |
                   ((processId & 0x1F) << 12) |
                   (increment & 0xFFF);
            ;
        }

        snowflake &operator=(unsigned long long l)
        {
            set(l);
            return *this;
        }

        snowflake(unsigned long long l)
        {
            set(l);
        }

        void set(unsigned long long l)
        {
            timestamp = (l >> 22) + DISCORD_EPOCH;
            workerId = (l & 0x3E0000) >> 17;
            processId = (l & 0x1F000) >> 12;
            increment = l & 0xFFF;
        }
    };
}

#define DISCORD_USER_AGENT "DiscordBot (Discpp, " DISCPP_VERSION ")"

#define DISCORD_CDN_EP "https://cdn.discordapp.com/"

#endif // __DISCPP_DEFINITIONS_H__