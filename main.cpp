#include "Window/App.hpp"
#include "Filesystem/ResourcesChecker.hpp"
int main() {
    ResourcesChecker::Check();
    App().Run();
    return 0;
}
