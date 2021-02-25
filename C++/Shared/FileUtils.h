#pragma once

using namespace Windows::Data::Json;

class FileUtils {

public:
	static void doNothing();
	static JsonObject ^loadJsonFile(Platform::String^ filename);
	static Platform::String ^doSomething();
};