// Example of using the GeographicLib::Geoid class
// $Id$

#include <iostream>
#include <exception>
#include <GeographicLib/Ellipsoid.hpp>

using namespace std;
using namespace GeographicLib;

int main() {
  try {
    Ellipsoid wgs84(Constants::WGS84_a(), Constants::WGS84_f());
    // Alternatively: const Ellipsoid& wgs84 = Ellipsoid::WGS84;
    cout << "The latitude half way between the equator and the pole is "
         << wgs84.InverseRectifyingLatitude(45) << "\n";
    cout << "XXXXXXXX "
         << wgs84.QuarterMeridian() << " "
         << wgs84.RectifyingLatitude(45) << " "
         << 90 - wgs84.RectifyingLatitude(90) << "\n";
    cout << "Half the area of the ellipsoid lies between latitudes +/-"
         << wgs84.InverseAuthalicLatitude(30) << "\n";
    cout << "The northernmost edge of a square Mercator map "
         << wgs84.InverseIsometricLatitude(180) << "\n";
    {
      Ellipsoid wgs84x(6e6, -0.1);
    cout << "The latitude half way between the equator and the pole is "
         << wgs84x.InverseRectifyingLatitude(45) << "\n";
    cout << "XXXXXXXX "
         << wgs84x.QuarterMeridian() << " "
         << wgs84x.RectifyingLatitude(45) << " "
         << 90 - wgs84x.RectifyingLatitude(90) << "\n";
    }

  }
  catch (const exception& e) {
    cerr << "Caught exception: " << e.what() << "\n";
    return 1;
  }
  return 0;
}
