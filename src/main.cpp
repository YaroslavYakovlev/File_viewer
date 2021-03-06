#include <iostream>
#include <fstream>

int main(){
  std::cout << "File viewer" << std::endl;
  std::ifstream file;
  char buffer[16];

  int count = 0;

  file.open("..\\src\\File\\words.txt", std::ios::binary);
  if(file.is_open()){
    while(!file.eof()){
      file.read(buffer, sizeof(buffer) - 1);
      buffer[file.gcount()] = 0;
      std::cout << buffer;
      }
    file.close();
  }else {
    std::cout << "This file could not be opened" << std::endl;
  }
  return 0;
}

// Разработайте простейший просмотрщик текстовых файлов. 
// В начале программы пользователь вводит путь к 
// текстовому файлу, который требуется открыть и просмотреть. 
// Внутренности файла необходимо вывести в стандартный вывод. 
// Программа должна работать для любых текстовых 
// файлов в формате TXT, но вы можете создать и 
// свой отдельный файл для теста. Главное, чтобы 
// файл был англоязычным, дабы избежать проблем с 
// кодировками.


// Для проверки того, был ли на самом деле открыт файл, используйте метод is_open. 
// Он вернёт true, если файл был благополучно открыт, и false, если 
// что-то пошло не так, к примеру, если путь к файлу невалидный.
// Файл надо считывать постепенно, отдельными фрагментами,
// ведь он может быть весьма большим. Для этого лучше всего 
// пользоваться методом gcount, так как он ещё вернёт количество 
// байт, которые были считаны по факту методом read. 
// Сами эти фрагменты могут храниться в специальном буфере, 
// как и в примере из лекций, но его размер и второй 
// аргумент к функции read надо рассчитать так, чтобы 
// выводились все символы, без обрезки последней буквы.
// Файл можно открыть в бинарном формате.