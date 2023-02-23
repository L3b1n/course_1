#include <fstream>
#include <iostream>
//#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

struct RRecord
{
  bool operator <= (RRecord const& r) const
  {
    if(fCex < r.fCex) return true;
    else if(fCex > r.fCex) return false;
    if(fUchastok < r.fUchastok) return true;
    else if(fUchastok > r.fUchastok) return false;
    if(fDetail < r.fDetail) return true;
    else if(fDetail > r.fDetail) return false;
    return true;
  }

  friend ifstream& operator >> (ifstream& fi, RRecord& rec)
  { 
    fi.read((char *)&rec, sizeof(rec));
    return fi;
  }

  friend ofstream& operator << (ofstream&  fo, RRecord const& aRec)
  { 
    fo.write((char *)&aRec, sizeof(aRec));
    return fo;
  }

  char name[36];   
  int fCex;
  int fUchastok;
  int fDetail;
  int fAmount;
};
//---------------------------------------------------------------------------

struct KRecordTxt
{
  KRecordTxt(RRecord& aRec) : r(aRec) { }
  RRecord & r;
  friend istream& operator >> (istream& fi, KRecordTxt& aRec)
  {
    std::string s;
    if(getline(fi, s))
    {
  
      istringstream ss(s);
      string sf;
      ss.getline(aRec.r.name, 36,';');
      getline(ss, sf, ';');
      aRec.r.fCex = stoi(sf);
      getline(ss, sf, ';');
      aRec.r.fUchastok = stoi(sf);
      getline(ss, sf, ';');
      aRec.r.fDetail = stoi(sf);
      getline(ss, sf, ';');
      aRec.r.fAmount = stoi(sf);
    }
    return fi;
  }

  friend ostream& operator << (ostream& fo, KRecordTxt const& rec)
  {
    fo << rec.r.name << " " << rec.r.fCex << " " << rec.r.fUchastok << " " << rec.r.fDetail << " " << rec.r.fAmount;
    return fo;
  }
};
//---------------------------------------------------------------------------

bool FGetRec(RRecord& r)
{
 //KRecordTxt i =;
 //cout << i << endl;
   cin >> r.fCex >> r.fUchastok >> r.fDetail >> r.fAmount;
   return true;
}

//---------------------------------------------------------------------------
void FFileToScreen(char * aFileName)
{
  cout << endl << "Output on display: " << endl;
  RRecord r;
  ifstream fi(aFileName, ios::binary);
  while(fi >> r){ cout << KRecordTxt(r) << endl;}
  cout << endl;
  fi.close();
}

//---------------------------------------------------------------------------
template <typename T>
auto GetLength(T& fi)
{
  streamoff n_pos = fi.tellg();  //return current position in file
  fi.seekg(0, std::ios_base::end); //делает текущим конец файла
  auto n2 = fi.tellg();
  fi.seekg(0);  //делает текущим начало файла
  auto n1 = fi.tellg();
  fi.seekg(n_pos);
  return n2 - n1;
}

void FBinFileToArray(char * aBinFileName)
{
  ifstream fi(aBinFileName, ios::binary);
  auto nFileLength = GetLength(fi);
  int nRecords = nFileLength / sizeof(RRecord);
  RRecord * pa  = new RRecord[nRecords];

  fi.read((char *)pa, nFileLength); // Весь файл читаем в массив

  for(int i = 0; i < nRecords; ++i){ cout << KRecordTxt(pa[i]) << endl;}
  delete[] pa;
}


void FAddToFile(char * aFileName)
{
  ofstream fo(aFileName, ios::app | ios::binary);
  RRecord r;
  fo.seekp(0, ios::end);
  // 2. Добавить одну запись в конец файла
  char xPrompt[] = "Введи новую запись по формату: \n'код цеха' 'код участка' 'код детали' 'количество деталей'";
  char * xPromptC = new char[strlen(xPrompt) + 1];
  //CharToOem(xPrompt, xPromptC);
  cout << xPromptC << endl;

  FGetRec(r);   // Ввести запись с клавиатуры
  cout << KRecordTxt(r) << endl;
  fo << r;
  fo.close();
}
//---------------------------------------------------------------------------

bool FIsSortedFile(char * aFileName)
{
  RRecord rPrev;
  RRecord r;
  ifstream fi(aFileName, ios::binary);
  bool xIsSorted = true;
  if(fi >> rPrev)
  {  
    while(fi >> r)
    { 
      if(!(rPrev <= r))
      { 
        xIsSorted = false; 
        break;
      }
      rPrev = r;
    }
  }
  return xIsSorted;
}
//---------------------------------------------------------------------------

void FBinToTxtFile(char * aFileNameBin, char * aFileNameTxt)
{
  ifstream fi(aFileNameBin, ios::binary);
  ofstream fOut(aFileNameTxt);
  RRecord rec;
  KRecordTxt rOut(rec);
  
  while(fi >> rec){ fOut << rOut << endl;}
  
}
//---------------------------------------------------------------------------

bool FTxtToBinFile(char * aFileNameTxt, char * aFileNameBin)
{
  bool b = false;
  ofstream fo(aFileNameBin, ios::binary);
  ifstream fi(aFileNameTxt);
  if(fi)
  { 
    RRecord rec;
    //cout << "sizeof(rec)=" << sizeof(rec) << endl;
    KRecordTxt rIn(rec);
    while(fi >> rIn){ fo << rec;}
    b = true;
  }
  return b;
}
//---------------------------------------------------------------------------

void FReplaceRecord(char * aFileNameBin)
{
  // 1. Ввести номер n заменяемой записи
  // 2. Ввести новую запись r
  // 3. Заменить n-ую файла на r

  fstream fi(aFileNameBin, ios::binary | ios::in | ios::out);
  int n;
  cout << "Enter the number of the record to be replaced: ";
  cin >> n;
  char xPrompt[] = "Введи новую запись по формату: \n'код цеха' 'код участка' 'код детали' 'количество деталей'";
  char * xPromptC = new char[strlen(xPrompt) + 1];
  //CharToOem(xPrompt, xPromptC);
  cout << xPromptC << endl;

  RRecord r;
  FGetRec(r);   // Ввести запись с клавиатуры

  streampos xPos = n * sizeof(r);   // Вычисляем номер позиции для n-ой записи
  fi.seekp(xPos);                   // Устанавливаем текущую позицию в xPos
  fi.write((char *)&r, sizeof(r));
  fi.close();
}
//---------------------------------------------------------------------------

void FReadRecord(fstream& fi, int n, RRecord& toRec)
{
  streampos xPos = n * sizeof(toRec);
  fi.seekp(xPos);
  fi.read((char *)&toRec,sizeof(toRec));
}
//---------------------------------------------------------------------------

void FWriteRecord(fstream& fo, int n, RRecord& fromRec)
{
  streampos xPos = n * sizeof(fromRec);
  fo.seekp(xPos);
  fo.write((char *)&fromRec, sizeof(fromRec));
}

//---------------------------------------------------------------------------
void FSortBinFile(fstream& f)
{
  auto nFileLength = GetLength(f);
  int n = nFileLength / sizeof(RRecord);
  RRecord xrec1, xrec2;
  for(int i = 1; i < n; ++i)
  {
    for(int j = 1; j <= n - i; ++j)
    {
      FReadRecord(f, j - 1, xrec1);
      FReadRecord(f, j, xrec2);
      if(!(xrec1 <= xrec2))  // т.е. xrec1 > xrec2
      {
        FWriteRecord(f, j - 1, xrec2);
        FWriteRecord(f, j, xrec1);
      }
    }
  }
}

int main(int argc, char* argv[])
{
  char xTxtFileNameOrig[] = "in.txt";   // Текстовый файл исходный (оригинальный)
  char xBinFileNameOrig[] = "in.bin";   // Бинарный файл исходный (оригинальный)
  char xBinFileNameOut[] = "out.bin";   // Бинарный файл выходной 
  char xTxtFileNameOut[] = "out.txt";   // Текстовый файл выходной 

  const int n = 9;
  string xPrmt[n] =
  {
    "1. Записать текстовый файл " + string(&xTxtFileNameOrig[0]) + " в бинарный файл " + string(&xBinFileNameOrig[0]),
    "2. Вывод содержимого бинарного файла " + string(&xBinFileNameOrig[0]) + " на экран",
    "3. Добавить одну запись в конец файла " + string(&xBinFileNameOrig[0]),
    "4. Проверить, что записи в файле " + string(&xBinFileNameOrig[0]) + " упорядочены по не убыванию \n"
    "   по следующим полям: код цеха, код участка.",
    "5. Вывести " + string(&xBinFileNameOrig[0]) + " в текстовый файл " + string(&xTxtFileNameOut[0]),
    "6. Заменить запись с заданным номером",
    "0. Завершить",
    "",
    "Выбери пункт меню, указав соответствующее число"
  };
  char * xPrmtC[n];
  for(int i = 0; i < n; ++i)
  {
    xPrmtC[i] = new char[strlen(xPrmt[i].c_str()) + 1];
    //CharToOem(xPrmt[i].c_str(), xPrmtC[i]);
  }
  for(;;)
  {
    for(int i = 0; i < n; ++i){  cout << xPrmtC[i] << endl;}
    cout << endl;

    int nMenu;
    cin >> nMenu;
    switch(nMenu)
    {
      case 0:
        break;
      case 1: // Копировать текстовый файл в бинарный
      {
        if (!FTxtToBinFile(xTxtFileNameOrig, xBinFileNameOrig))
          cout << "Unsuccessful copying to binary file" << endl;
        FBinFileToArray(xBinFileNameOrig);
        // Сортируем
        fstream fio(xBinFileNameOrig, ios::binary | ios::in | ios::out);
        FSortBinFile(fio);       // ====================================== СОРТИРОВКА бинарного файла =========
        fio.close();
      }
        break;
      case 2: // Копировать бинарый файл на экран дисплея
      {
        FFileToScreen(xBinFileNameOrig);
      }
        break;
      case 3: // Добавить новую запись в конец бинарного файла
        FAddToFile(xBinFileNameOrig);
        break;
      case 4: // Выяснить, упорядочен файл или нет
      {
        if(FIsSortedFile(xBinFileNameOrig))
          cout << "Sorted\n" << endl;
        else
          cout << "No sorted\n" << endl;
      }
        break;
      case 5:   // Копировать бинарный файл в текстовый
        FBinToTxtFile(xBinFileNameOrig, xTxtFileNameOut);
        break;
      case 6:   // В бинарном файле заменить запись (№ n) на другую
        FReplaceRecord(xBinFileNameOrig);
        break;
    }
    if(nMenu == 0) break;
  }
  return 0;
}
//---------------------------------------------------------------------------

