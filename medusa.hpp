#include <array>
#include <string>
#include <string_view>

class medusa{
    public:
        medusa(float lat, float lon);
        std::string_view convert();
    private:
        static constexpr auto LAT_OFFSET{90};
        static constexpr auto LON_OFFSET{180};
        static constexpr auto DEGREES_PER_MINUTE{1.0f/60.0f};

        static constexpr std::array<char , 23> mCharacterTable{{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W'}};
        float mLat{};
        float mLon{};
        std::string mLocator{};
};
