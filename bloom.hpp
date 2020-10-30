/**
 * MIT License
 *
 * Copyright (c) 2020 Andy Bui
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#ifndef BLOOM_HPP
#define BLOOM_HPP

#include <math.h>
#include <iostream>
#include <cstdint>

class BloomFilter {

private:
    // Number of elements that will be hashed
    int elements;

    // Size of bitmap
    int size;

    // Number of hash functions used
    int num_hash;

    // False-positive rate
    double fp_rate;

    // Salts used for hashing
    std::string salts[50] = {
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

    int calculateSize(int elements, double fp_rate);
    double calculateNumHash(int elements, int size);

public:
    BloomFilter(int elements);

    BloomFilter(int elements, double fp_rate);

    double getSize();

    int getNumHash();

};

#endif
