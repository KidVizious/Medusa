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
        static constexpr std::array<char , 18> mFieldValues{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'};
        float mLat{};
        float mLon{};
        std::string mLocator{};
};
