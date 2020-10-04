include_directories(${COURRENT_SOURCE_DIR})
add_executable(factory factory.cc factory_main.cc product.h concrete_factory.h concrete_product.h)
