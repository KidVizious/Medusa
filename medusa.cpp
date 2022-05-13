#include "medusa.hpp"
#include "degrees.hpp"
#include <cctype>
#include <cmath>
#include <sstream>
#include <cstdint>
#include <iostream>

medusa::medusa(float lat, float lon): mLat(lat + LAT_OFFSET), mLon(lon + LON_OFFSET){
}

std::string_view medusa::convert(){
    auto const lon_field = mCharacterTable[mLon / 20];
    auto const lat_field = mCharacterTable[mLat / 10];

    auto lon_square_intermediate = fmod(mLon, 20.0f);
    auto lon_square = lon_square_intermediate / 2;
    auto lat_square = fmod(mLat, 10);

    auto lon_sub_square = fmod(lon_square_intermediate,  2);
    lon_sub_square /= .083;


    auto lat_sub_square = fmod(lat_square,1) / 0.0416;

    std::stringstream outputString{};
    outputString
        << lon_field
        << lat_field
        << static_cast<uint32_t>(lon_square)
        << static_cast<uint32_t>(lat_square)
        << mCharacterTable[static_cast<uint32_t>(lon_sub_square)]
        << mCharacterTable[static_cast<uint32_t>(lat_sub_square)];
    mLocator = outputString.str();
    return mLocator;
}
