#include <iostream>
#include <memory>
#include <utility>
#include <vector>

namespace Ex9
{
struct MediaAsset
{
    virtual ~MediaAsset() = default;
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(std::wstring artist_, std::wstring title_) : artist{std::move(artist_)}, title{std::move(title_)}
    {
        std::cout << "constructor call" << std::endl;
    }
    ~Song() override { std::cout << "destructor call" << std::endl; }
};

std::unique_ptr<Song> SongFactory(const std::wstring &artist, const std::wstring &title)
{
    return make_unique<Song>(artist, title);
}

void test()
{
    auto song = SongFactory(L"Michael Jackson", L"Beat It");
    std::cout << "after object construction" << std::endl;
}

void songVector()
{
    std::vector<std::unique_ptr<Song>> songs;
    songs.push_back(std::make_unique<Song>(L"B'z", L"Juice"));
    songs.push_back(std::make_unique<Song>(L"Namie Amuro", L"Funky Town"));
    songs.push_back(std::make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de"));

    // compiler error when not reference
    for (const auto &song : songs)
    {
        std::wcout << L"Artist: " << song->artist << L" Title: " << song->title << std::endl;
    }
}
}  // namespace Ex9
