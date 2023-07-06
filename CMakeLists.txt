cmake_minimum_required(VERSION 3.16) #versione di CMake
project(sir_model VERSION 0.1.0)

# abilita il supporto per i test, tra cui l'opzione BUILD_TESTING usata sotto
include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# richiedi l'uso di C++17, senza estensioni non-standard offerte dal compilatore usato 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# abilita warning
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra")

# abilita l'address sanitizer e l'undefined-behaviour sanitizer in debug mode
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")

include_directories(sir_model PUBLIC libraries) 

add_executable(sir_model main.cpp sir_model.cpp sir_model_graph.cpp user_interface.cpp) #crea un eseguibile chiamato sir_model

# se il testing e' abilitato...
#   per disabilitare il testing, passare -DBUILD_TESTING=OFF a cmake durante la fase di configurazione
if (BUILD_TESTING)

  # aggiungi l'eseguibile statistics.t
  add_executable(sir_model.t sir_model.test.cpp sir_model.cpp sir_model_graph.cpp)
  # aggiungi l'eseguibile statistics.t alla lista dei test
  add_test(NAME sir_model.t COMMAND sir_model.t)

endif()
