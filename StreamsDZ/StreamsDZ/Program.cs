
using System.Diagnostics;

//1-----------------------------------------------------------------
/*string basePath = AppDomain.CurrentDomain.BaseDirectory; 
string targetPath = @"D:\Rider pg\ride prochekt\StreamsDZ\Proches\bin\Debug\net8.0\Proches.exe";
string relativePath = Path.GetRelativePath(basePath, targetPath);

Console.WriteLine($"Process with id:( {Process.GetCurrentProcess().Id} ) started");

ProcessStartInfo psi = new ProcessStartInfo
{
    FileName = relativePath,
    Arguments = "Tom Raul Omar Dmitriy",
    RedirectStandardOutput = true

    
};

using Process process = new Process { StartInfo = psi };

process.EnableRaisingEvents = true;
process.Exited += (sender, e) => Console.WriteLine($"Child process with id:( {process.Id} ) finished");
process.OutputDataReceived += (sender, e) => Console.WriteLine(e.Data);

process.Start();
Console.WriteLine($"Child process with id:( {process.Id} ) started");

process.BeginOutputReadLine();

process.WaitForExit();


Console.WriteLine($"Process with id:( {Process.GetCurrentProcess().Id} ) finished");*/


//2---------------------------------------------------------------------------------

/*
string basePath = AppDomain.CurrentDomain.BaseDirectory; 
string targetPath = @"D:\Rider pg\ride prochekt\StreamsDZ\Proches\bin\Debug\net8.0\Proches.exe";
string relativePath = Path.GetRelativePath(basePath, targetPath);

Console.WriteLine($"Process with id:( {Process.GetCurrentProcess().Id} ) started");

ProcessStartInfo psi = new ProcessStartInfo
{
    FileName = relativePath,
    Arguments = "Tom Raul Omar Dmitriy",
    RedirectStandardOutput = true

    
};

using Process process = new Process { StartInfo = psi };

process.EnableRaisingEvents = true;
process.Exited += (sender, e) => Console.WriteLine($"Child process with id:( {process.Id} ) finished");
process.OutputDataReceived += (sender, e) => Console.WriteLine(e.Data);



process.Start();
Console.WriteLine($"Child process with id:( {process.Id} ) started");

process.BeginOutputReadLine();
Console.WriteLine($"Process with id:( {Process.GetCurrentProcess().Id} ) finished");

Console.WriteLine("Выберите действие (1 - ожидать завершения, 2 - принудительно завершить): ");
string choice = Console.ReadLine();

if (choice == "1")
{
    process.WaitForExit(); 
    Console.WriteLine($"Child process exited with code: {process.ExitCode}");
}
else if (choice == "2")
{
    process.Kill();  
    Console.WriteLine("Child process was terminated forcefully.");
}
*/

//3----------------------------------------------------------------------------------------


/*string basePath = AppDomain.CurrentDomain.BaseDirectory;
string targetPath = @"D:\Rider pg\ride prochekt\StreamsDZ\Calculator\bin\Debug\net8.0\Calculator.exe";
string relativePath = Path.GetRelativePath(basePath, targetPath);

string num1, num2, operation;


Console.Write("Enter the first number: ");
num1 = Console.ReadLine();

Console.Write("Enter the second number: ");
num2 = Console.ReadLine();

Console.Write("conduct the operation: ");
operation = Console.ReadLine();


Console.WriteLine("");

Console.WriteLine($"Process with id:( {Process.GetCurrentProcess().Id} ) started");

ProcessStartInfo psi = new ProcessStartInfo
{
    FileName = relativePath,
    Arguments = $"{num1} {num2} {operation}",
    RedirectStandardOutput = true
};

using Process process = new Process { StartInfo = psi };

process.EnableRaisingEvents = true;
process.Exited += (sender, e) => Console.WriteLine($"Child process with id:( {process.Id} ) finished");
process.OutputDataReceived += (sender, e) => Console.WriteLine(e.Data);



process.Start();
Console.WriteLine($"Child process with id:( {process.Id} ) started");

process.BeginOutputReadLine();

process.WaitForExit();
Console.WriteLine($"Process with id:( {Process.GetCurrentProcess().Id} ) finished");*/


//4----------------------------------------------------------------------------------------


string basePath = AppDomain.CurrentDomain.BaseDirectory;
string targetPath = @"D:\Rider pg\ride prochekt\StreamsDZ\Number of words\bin\Debug\net8.0\Number of words.exe";
string relativePath = Path.GetRelativePath(basePath, targetPath);

string FilePath, word;

Console.Write("Specify the path to the file: ");
FilePath = Console.ReadLine();

Console.Write("Enter word: ");
word = Console.ReadLine();


Console.WriteLine("");
Console.WriteLine($"Process with id:( {Process.GetCurrentProcess().Id} ) started");

ProcessStartInfo psi = new ProcessStartInfo
{
    FileName = relativePath,
    Arguments = $"{FilePath} {word}",
    RedirectStandardOutput = true
};


using Process process = new Process { StartInfo = psi };

process.EnableRaisingEvents = true;
process.Exited += (sender, e) => Console.WriteLine($"Child process with id:( {process.Id} ) finished");
process.OutputDataReceived += (sender, e) => Console.WriteLine(e.Data);


process.Start();
Console.WriteLine($"Child process with id:( {process.Id} ) started");

process.BeginOutputReadLine();

process.WaitForExit();
Console.WriteLine($"Process with id:( {Process.GetCurrentProcess().Id} ) finished");

















