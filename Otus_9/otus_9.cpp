﻿#include "args/cmd_args.h"    
#include "duplicate/duplicate_finder.h"
#include "file/file_filter.h" 
#include "hash/hash_crc32.h"
#include "hash/hash_md5.h"
#include "hash/ihash.h"
/*! \mainpage Otus_9 (Bayan)
 *
 * \r\n  Поиск файлов дубликатов в папке
 *
 */

 /**
 * \brief  Возвращает указатель на фабрику классов расчета хэш функций
 * \details возвращенная фабрика создает объекты реализующие алгоритм iHash.
 * \param[in] aAlg - алгоритм хэширования
 * \return TDefaultValue - фабрика классов реализующих интерфейс IHash
 */
boost::function<std::unique_ptr<IHash>()> GetHashCalculator(const CmdArgs::HashAlg aAlg) {
    switch (aAlg) {
        default:
            throw std::logic_error("Unknown hash algorithm");
        break;
        case CmdArgs::HashAlg::crc32:
            return  boost::factory<std::unique_ptr<HashCRC32>>();
        break;
        case CmdArgs::HashAlg::md5:
            return boost::factory<std::unique_ptr<HashMD5>>();
        break;
    }
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    try {
        auto args = GetArgs(argc, argv);
        if (!args.StartProcess)
            return 0;
        FilesFilter fileFilter{ {args.Dirs, args.Dropped, args.Lvl}, {args.MinFileSize, args.Masks} };
        DuplicateFinder finder { GetHashCalculator(args.Algorithm), args.BlockSize};
        finder.OutputDuplicated(fileFilter.GetFiles(), true);
    } 
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}