#include "generate_output.h"

int main()
{
    clear_file();
    copy_directives();

    for (int i = 0; i < FILES_QUANTITY; i++)
    {
        ifstream input_file(INPUT_FILES[i]);
        if (input_file.is_open())
        {
            copy_file(input_file);
            input_file.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }
    return 0;
}

void clear_file()
{
    ofstream output_file(OUTPUT_FILE, ios_base::out | ios_base::trunc);
    output_file.close();
}

void copy_directives()
{
    ofstream output_file(OUTPUT_FILE, ios_base::app);
    string line;

    if (output_file.is_open())
    {
        for (auto d : DIRECTIVES)
        {
            output_file << d;
        }
        output_file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

void copy_file(ifstream &input_file)
{
    ofstream output_file(OUTPUT_FILE, ios_base::app);
    string line;
    if (output_file.is_open())
    {
        while (getline(input_file, line))
        {
            if (!exclude_line(line))
            {
                output_file << line;
                output_file << endl;
            }
        }
        output_file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

bool exclude_line(string line)
{
    bool output = false;
    if (line.find("#") != string::npos ||
        line.find("using") != string::npos)
    {
        output = true;
    }
    return output;
}