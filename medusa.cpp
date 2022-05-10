#include "medusa.hpp"
#include <cmath>

medusa::medusa(float lat, float lon): mLat(lat + LAT_OFFSET), mLon(lon + LON_OFFSET){
}

std::string_view medusa::convert(){
    auto const lonField = static_cast<int>(mLon) / 20;
    auto const latField = static_cast<int>(mLat) / 10;
    auto const lonSquare = std::floor(static_cast<int>(mLon) % 20 / 2);
    auto const latSquare = std::floor(static_cast<int>(mLat) % 10);
    mLocator = std::string(1, mFieldValues[lonField]) + std::string(1, mFieldValues[latField]) + std::to_string(static_cast<int>(lonSquare)) + std::to_string(static_cast<int>(latSquare));
    return mLocator;
}
