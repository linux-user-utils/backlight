#include <filesystem>
#include <libluu/utility.hpp>
#include <libluu/backlight.hpp>
#include <libluu/logging.hpp>
#include <libluu/parse_arguments.hpp>
#include <vector>

using std::vector;
using std::filesystem::path;
using namespace logging;
using namespace utility;
using namespace backlight;

/** @brief Single argument increments/decrements current brightness by N% */
int main(const int argc, const char *argv[]) {
  int percentage = (-1) * arguments::parse_args(argc, argv);
  for (auto config_file : default_paths()) {
    vector<path> devices = get_backlights_from_config_file(config_file);
    if (devices.empty()) {
      devices = scan_for_valid_backlights();
    }
    if (!devices.empty()) {
      for (auto device : devices) {
        backlight::adjust_brightness_by_increment(device, percentage);
      }
    }
  }
  return (EXIT_SUCCESS);
}