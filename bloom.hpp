#ifndef BLOOM_HPP
#define BLOOM_HPP

#define ROUND_UP(x, y) ((((x) + (y) - 1) / (y)) * (y))
#define CEILING(x, y) (((x) + (y) - 1) / (y))

#include <math.h>
#include <iostream>
#include <cstdint>

class BloomFilter {

private:

    // Size of bitmap
    uint32_t size;

    // Number of hash functions used
    int num_hash;

    // False-positive rate
    double fp_rate;

    // Bitmap
    uint32_t* bitmap;

    // Salts used for hashing
    const char* salts[50] = {
        "FullmetalAlchemist:Brotherhood",
        "Gintama(2015)",
        "HunterxHunter(2011)",
        "Steins;Gate",
        "GingaEiyuuDensetsu",
        "Gintama(2011);",
        "ShingekinoKyojinSeason3Part2",
        "Gintama:Enchousen",
        "3-gatsunoLion2ndSeason",
        "KiminoNawa.",
        "KoenoKatachi",
        "Gintama.(2017)",
        "Gintama(2006)",
        "GintamaMovie2:Kanketsu-hen-YorozuyayoEienNare",
        "Clannad:AfterStory",
        "Owarimonogatari2ndSeason",
        "CodeGeass:HangyakunoLelouchR2",
        "Haikyuu!!:KarasunoKoukouvs.ShiratorizawaGakuenKoukou",
        "MobPsycho100II",
        "Gintama.:ShiroganenoTamashii-hen-Kouhan-sen",
        "SentoChihironoKamikakushi",
        "KizumonogatariIII:Reiketsu-hen",
        "Gintama.:ShiroganenoTamashii-hen",
        "Kaguya-samawaKokurasetai?:Tensai-tachinoRenaiZunousen",
        "CowboyBebop",
        "MadeinAbyssMovie3:FukakiTamashiinoReimei",
        "ShouwaGenrokuRakugoShinjuu:SukerokuFutatabi-hen",
        "ShigatsuwaKiminoUso",
        "Haikyuu!!SecondSeason",
        "MonogatariSeries:SecondSeason",
        "MadeinAbyss",
        "MushishiZokuShou2ndSeason",
        "Fate/staynightMovie:HeavensFeel-III.SpringSong",
        "HajimenoIppo",
        "MononokeHime",
        "Monster",
        "MushishiZokuShou",
        "RurouniKenshin:MeijiKenkakuRomantan-Tsuioku-hen",
        "VinlandSaga",
        "CodeGeass:HangyakunoLelouch",
        "GreatTeacherOnizuka",
        "Mushishi",
        "SeishunButaYarouwaYumemiruShoujonoYumewoMinai",
        "HajimenoIppo:NewChallenger",
        "KimetsunoYaiba",
        "NatsumeYuujinchouShi",
        "HowlnoUgokuShiro",
        "SuzumiyaHaruhinoShoushitsu",
        "TengenToppaGurrenLagann",
        "OokamiKodomonoAmetoYuki"
    };

    uint32_t calculateSize(uint32_t elements, double fp_rate);
    int calculateNumHash(uint32_t elements, uint32_t size);
    uint64_t hash(const char* str, const char* salt);
    inline void bitmap_set(uint32_t bit_index);
    inline uint32_t bitmap_check(uint32_t bit_index);


public:
    BloomFilter(uint32_t elements);
    BloomFilter(uint32_t elements, double fp_rate);
    void insert(const char* str);
    int check(const char* str);

};

#endif
