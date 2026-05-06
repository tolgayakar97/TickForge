add_library(Strategy
    src/DailyMeanExitStrategy.cpp
)

target_include_directories(Strategy
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)