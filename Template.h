/*
This is the template application for Matrix OS
*/

#pragma once

#include "MatrixOS.h"
#include "Application.h"

class Template : public Application {
 public:
  inline static Application_Info info = {
      .name = "Template",
      .author = "203 Systems",
      .color = Color(0xFFFFFF),
      .version = 1,
      .visibility = true,
  };

  void Setup(const vector<string>& args) override;
  void Loop() override;
  void End() override;
};
