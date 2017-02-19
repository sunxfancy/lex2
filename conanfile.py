from conans import ConanFile, CMake

class PLex(ConanFile):
    name = "plex"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = "estring/1.2@sunxfancy/stable"
    exports_sources = "*"
    generators = "cmake"

    def build(self):
        cmake = CMake(self.settings)
        self.run('cmake %s %s' % (self.conanfile_directory, cmake.command_line))
        self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.h", dst="include")
        self.copy("*.dll", dst="lib", src="lib")
        self.copy("*.lib", dst="lib", src="lib")
        self.copy("*.so", dst="lib", src="lib")
        self.copy("*.a", dst="lib", src="lib")
        self.copy("*.dylib", dst="lib", src="lib")

    def package_info(self):
        self.cpp_info.libs = ["plex"]
