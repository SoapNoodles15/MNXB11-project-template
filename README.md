### How to build

To build the library you need to clone the repository of CLI11 (using `git clone "repo link"`) into the dependencies folder and then copy the relevant header files into the external/include/ folder. The makefile already has that folder listed in the includes so you should be freely able to include the headers in the code.
For Vince's CSV Parser, repeat the steps but copy the single include "csv.hpp" header file.
Do the same for the Howard Hinnant's date library, but copy the "date" folder from /include/ into the /external/include/ folder in the project.
