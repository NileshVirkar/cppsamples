using System;

// CA1008: Enums should have zero value
// This enum violates CA1008 because it does not define a zero value
public enum Color
{
    Red = 1,
    Green = 2,
    Blue = 3
}

class EnumExample
{
    static void Main(string[] args)
    {
        Color color = default;
        Console.WriteLine($"Default value of Color enum: {color}"); // Will print 0, which is not a valid value
    }
}
