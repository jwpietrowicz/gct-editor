#include <string>
#include <fstream>
//#include <iterator>
#include <iostream>
//#include <algorithm>
#include <cerrno>

using namespace std;

void pressAnyKeyToContinue()
{
	cin.sync();
	cout << endl << "Press Enter to continue..." << endl;
	cin.get();
}
fstream * openInputFile()
{
	string fileName;
	cout << "Enter a valid GCT filename: ";
	cin >> fileName;
	fstream * openFile(new fstream(fileName.c_str());
	if (!openFile -> is_open())
	{
		cerr << "Error: " << fileName << "-> " << strerror(errno) << "\n";
		delete openFile;
		openFile = 0;
	} else {
		cout << "The codeset has been opened successfully\n";
	return openFile;
	
}
int main(int argc, char *argv[])
{
char * memchunk,code;
string fterm = "\xF0\x00\x00\x00";
fstream *gct(openInputFile(), ios::in | ios::out | ios::binary);
if (gct)
{
streampos begin,end;
begin = gct.tellg();
gct.seekg (0, ios::end);
end = gct.tellg();
cout << "RSBE01\nSize: << (end-begin) << "\nSearching for full terminator...\n";
memchunk = new char [4];
gct.seekg((end-4));
gct.read(memchunk,4);
if (memchunk = fterm)
{
 cout << "Full terminator found.\nTest Code [InvalidCode]\n04928890 60000000\n04928894 60000000\nSize: 16 bytes.Inserting test code...\n"; 
}else{
cout << "Full terminator is missing! Your GCT may be corrupted.";
}
code = new char [16];
code = {0x04,0x92,0x88,0x90,0x60,0x00,0x00,0x00,0x04,0x92,0x88,0x94,0x60,0x00,0x00,0x00};
gct.seekp(0, (ios::end)-4);
gct.write(code,16);
gct.seekp(0, ios::end);
gct.write(memchunk,4);
delete [] memchunk;
delete [] code;
gct.seekp (0, ios::end);
gct->close();
delete gct;
} else {
cout << "There was an error opening your codeset\n";
}
pressAnyKeyToContinue();
return 0;
}


