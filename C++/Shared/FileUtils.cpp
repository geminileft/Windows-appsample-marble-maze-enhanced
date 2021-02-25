#include "pch.h"
#include "FileUtils.h"
#include "BasicLoader.h"

using namespace Windows::Data::Json;

void FileUtils::doNothing() {

}

JsonObject ^FileUtils::loadJsonFile(Platform::String^ filename)
{
    auto myReader = ref new BasicReaderWriter();
    Platform::Array<byte>^ bytecode = myReader->ReadData(filename);
    std::string s((const char*)&(bytecode[0]), bytecode->Length);
    std::wstring w_str = std::wstring(s.begin(), s.end());
    const wchar_t* w_chars = w_str.c_str();
    auto newString = ref new Platform::String(w_chars);
    return JsonObject::Parse(newString);
}

Platform::String^ FileUtils::doSomething() {
    auto myReader = ref new BasicReaderWriter();
    Platform::Array<byte>^ bytecode = myReader->ReadData(L"MyText.txt");
    std::string s((const char*)&(bytecode[0]), bytecode->Length);
    std::wstring w_str = std::wstring(s.begin(), s.end());
    const wchar_t* w_chars = w_str.c_str();
    return ref new Platform::String(w_chars);
}