#include "GetProjectPath.h"

#include <stdexcept>

#include "GetExecutablePath.h"
#include "StringHelper.h"

namespace utils
{
namespace
{
constexpr auto fileNotFoundMessage{"Project directory not found in path: "};
}

std::string getProjectPath(const std::string& projectName)
{
    const std::string currentPath = getExecutablePath();
    const auto projectNamePosition = currentPath.find(projectName);
    if (projectNamePosition == std::string::npos)
    {
        throw std::runtime_error{fileNotFoundMessage + currentPath};
    }

    auto projectPath = utils::substring(currentPath, 0, projectNamePosition + projectName.length() + 1);
    return projectPath;
}
}