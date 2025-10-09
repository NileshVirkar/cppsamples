using System;


class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Hello, World from .NET 9.0.305!");
        // Example usage of the problematic class
        using (var obj = new BadDisposeExample())
        {
            // ...
        }
    }
}

// CA1816: GC.SuppressFinalize should not be called unless the type has a finalizer
public class BadDisposeExample : IDisposable
{
    public void Dispose()
    {
        // This is incorrect: GC.SuppressFinalize should only be called if the class has a finalizer
        GC.SuppressFinalize(this); // CA1816 violation
    }
}
