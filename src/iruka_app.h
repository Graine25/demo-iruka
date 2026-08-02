
// iruka - ReXGlue Recompiled Project
//
// This file is yours to edit. 'rexglue migrate' will NOT overwrite it.
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>

class IrukaApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<IrukaApp>(new IrukaApp(ctx, "iruka",
        PPCImageConfig));
  }

  // Override virtual hooks for customization:
  std::optional<rex::PathConfig> OnFinalizePaths(
      const rex::PathConfig& defaults,
      std::function<void(rex::PathConfig)> resume) override {
    (void)resume;
    rex::PathConfig paths = defaults;
    const std::string root = rex::cvar::GetFlagByName("iruka_data_root");
    if (!root.empty()) {
      std::filesystem::path configured_root = root;
      if (configured_root.is_relative()) {
        configured_root = defaults.config_path.parent_path() / configured_root;
      }
      paths.game_data_root = configured_root.lexically_normal();
    }
    return paths;
  }

  // void OnPostInitLogging() override {}
  // void OnPreSetup(rex::RuntimeConfig& config) override {}
  // void OnLoadXexImage(std::string& xex_image) override {}
  // void OnPostSetup() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // void OnShutdown() override {}
  // void OnConfigurePaths(rex::PathConfig& paths) override {}
};
