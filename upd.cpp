// upd.cpp -*- C++ -*-

/*
 * Copyright (c) 2023 S-Patriarch
 * Обновление системы Linux семейства Debian.
 */

#include <iostream>
#include <cstdlib>
#include <string>

/** Точка входа...
 */ 
auto
main(int argc, char *argv[]) -> int
{
  if (argc != 2)
    {
      std::cout 
        << "upd 2.0\n"
        << "Использование: upd [параметр]\n\n"
        << "upd - помошник проведения обновления и очистки системы "
        << "семейства Debian\n"
        << "для людей с очень маленьким опытом работы в ОС Linux.\n\n"
        << "Основные параметры:\n"
        << "  -f  обновление системы до последней версии с последующей "
        << "очисткой\n"
        << "  -u  обновление системы до последней версии\n"
        << "  -c  очистка системы" 
        << std::endl;
      return 0;
    }

  std::string argString {*(argv + 1)};

  if (argString == "-f")
    {
      /** Обновление системы до последней версии.
       */
      std::system("sudo apt update && sudo apt full-upgrade -y");

      /** Удаление неиспользуемых программ и ядер.
       */
      std::system("sudo apt autoremove -y");

      /** Удаление старых скаченных файлов архивов.
       */
      std::system("sudo apt autoclean -y");

      /** Удаление скаченных файлов архивов.
       */
      std::system("sudo apt clean -y");
    }
  else if (argString == "-u")
    {
      /** Обновление системы до последней версии.
       */
      std::system("sudo apt update && sudo apt full-upgrade -y");
    }
  else if (argString == "-c")
    {
      /** Удаление неиспользуемых программ и ядер.
       */
      std::system("sudo apt autoremove -y");

      /** Удаление старых скаченных файлов архивов.
       */
      std::system("sudo apt autoclean -y");

      /** Удаление скаченных файлов архивов.
       */
      std::system("sudo apt clean -y");
    }
  else
    std::cout 
      << "E: Параметр командной строки [" 
      << argString 
      << "] непонятен." 
      << std::endl;

  return 0;
}