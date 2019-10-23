workspace "OpenGL"
	architecture "x64"
	startproject "OpenGL"
	systemversion "latest"
	cppdialect "C++17"

	configurations
	{
		"Debug"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project "OpenGL"
	location "OpenGL"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("build/" .. outputdir .. "/%{prj.name}")
	
	defines
	{
		"GLEW_STATIC"
	}

	files
	{
		"%{prj.name}/include/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"vendor",
		"vendor/GLFW/include",
		"vendor/GLEW/include",
		"%{prj.name}/include"
	}
	
	libdirs 
	{ 
	"vendor/GLFW/lib", 
	"vendor/GLEW/lib"
	}
	
	links 
	{
		"opengl32",
		"GLFW3",
		"glew32s"
	}
	
	