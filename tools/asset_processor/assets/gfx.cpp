#include "gfx.h"
#include "util.h"
#include <json.hpp>

std::filesystem::path GfxAsset::generateAssetPath() {
    std::filesystem::path pngPath = this->path;
    if (pngPath.extension() == ".lz") {
        pngPath.replace_extension("");
    }
    pngPath.replace_extension(".png");
    return pngPath;
}

void GfxAsset::convertToHumanReadable(const std::vector<char>& baserom) {
    (void)baserom;

    std::filesystem::path toolsPath = "tools";
    std::vector<std::string> cmd;
    cmd.push_back(toolsPath / "gbagfx" / "gbagfx");
    cmd.push_back(this->path);
    cmd.push_back(this->assetPath);
    if (this->asset.contains("options")) {
        for (const auto& it : this->asset["options"].items()) {
            cmd.push_back("-" + it.key());
            cmd.push_back(to_string(it.value()));
        }
    }
    check_call(cmd);
}

void GfxAsset::buildToBinary() {
    std::filesystem::path toolsPath = "tools";
    std::vector<std::string> cmd;
    cmd.push_back(toolsPath / "gbagfx" / "gbagfx");
    cmd.push_back(this->assetPath);
    cmd.push_back(this->path);
    check_call(cmd);
}