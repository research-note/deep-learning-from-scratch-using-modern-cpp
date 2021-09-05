# Bazel Template For Class

In this stage we step it up and showcase how to integrate multiple ```cc_library``` targets from different packages.

this BUILD file is in a subdirectory called lib. In Bazel, subdirectories containing BUILD files are known as packages. The new property ```visibility``` will tell Bazel which package(s) can reference this target, in this case the ```//main``` package can use ```Cuboid``` library. 

```
cc_library(
    name = "Cuboid",
    // srcs = ["Cuboid.cc"],
    hdrs = ["Cuboid.hpp", "Cuboid.cc"],
    visibility = ["//main:__pkg__"],
)
```

To use our ```Cuboid.cc``` libary, an extra dependency is added in the form of //path/to/package:target_name, in this case, it's ```//lib:Cuboid```

```
cc_binary(
    name = "Grid",
    // srcs = ["Grid.cc"],
    hdrs = ["Grid.hpp", "Grid.cc"],
    deps = [
        ":Grid",
        "//lib:Cuboid",
    ],
)
```

To build this example you use (notice that 3 slashes are required in windows)
```
bazel build --config=clang_config //main:main

# In Windows, note the three slashes

bazel build --config=clang_config ///main:main
```
