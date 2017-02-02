#pragma once

#define EXPORT_TEST(NAME)\
namespace NAME { __declspec(dllexport) int ref() { return 0; } }

#define IMPORT_TEST(NAME)\
namespace NAME { int ref(); }\
static int dummy_##NAME = NAME::ref();
