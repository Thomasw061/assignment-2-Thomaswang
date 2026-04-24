// -----------------------------------------------------------------------------
// gardening.cpp
//
// Computes mixing proportions (M1, M2, M3) for three fertilizer ingredients
// such that the resulting blend has equal proportions of nitrogen (N),
// phosphorus (P), and potassium (K) — a "balanced" fertilizer.
//
// The solution is derived by substitution from a 3x3 linear system.
// See assignment description (Problem 2) for the full derivation.
// -----------------------------------------------------------------------------

#include <iostream>

// -----------------------------------------------------------------------------
// Prompts the user to enter NPK proportions for all three ingredients.
// Values are passed by reference and filled in place.
// -----------------------------------------------------------------------------
void readIngredients(
    double &n1, double &p1, double &k1,
    double &n2, double &p2, double &k2,
    double &n3, double &p3, double &k3)
{
    std::cout << "Enter n1 (nitrogen in ingredient 1): ";
    std::cin >> n1;
    std::cout << "Enter p1 (phosphorus in ingredient 1): ";
    std::cin >> p1;
    std::cout << "Enter k1 (potassium in ingredient 1): ";
    std::cin >> k1;

    std::cout << "Enter n2 (nitrogen in ingredient 2): ";
    std::cin >> n2;
    std::cout << "Enter p2 (phosphorus in ingredient 2): ";
    std::cin >> p2;
    std::cout << "Enter k2 (potassium in ingredient 2): ";
    std::cin >> k2;

    std::cout << "Enter n3 (nitrogen in ingredient 3): ";
    std::cin >> n3;
    std::cout << "Enter p3 (phosphorus in ingredient 3): ";
    std::cin >> p3;
    std::cout << "Enter k3 (potassium in ingredient 3): ";
    std::cin >> k3;
}

// -----------------------------------------------------------------------------
// Solves the linear system for M1 using equation (6) from the derivation.
//
// The shared denominator term (n2 - n3 + p3 - p2) appears in both the
// numerator and denominator of M1, so it is factored out as sharedDenom.
//
// M1 = numerator / denominator  (equation 6)
// -----------------------------------------------------------------------------
double solveM1(
    double n1, double p1, double k1,
    double n2, double p2, double k2,
    double n3, double p3, double k3)
{
    double sharedDenom = n2 - n3 + p3 - p2;

    double numerator =
        (k3 - n3)
        + (n3 - n2 + k2 - k3) * (p3 - n3) / sharedDenom;

    double denominator =
        (k3 - n3) + (n1 - k1)
        + (n3 - n2 + k2 - k3) * (n1 - n3 + p3 - p1) / sharedDenom;

    return numerator / denominator;
}

// -----------------------------------------------------------------------------
// Solves for M2 given M1, using equation (5) from the derivation.
// -----------------------------------------------------------------------------
double solveM2(
    double m1,
    double n1, double p1,
    double n2, double p2,
    double n3, double p3)
{
    double numerator = (p3 - n3) - m1 * (n1 - n3 + p3 - p1);
    double denominator = n2 - n3 + p3 - p2;

    return numerator / denominator;
}

// -----------------------------------------------------------------------------
// Solves for M3 given M1 and M2, using equation (4): M3 = 1 - M1 - M2.
// -----------------------------------------------------------------------------
double solveM3(double m1, double m2)
{
    return 1.0 - m1 - m2;
}

// -----------------------------------------------------------------------------
// Prints the three mixing proportions to standard output.
// -----------------------------------------------------------------------------
void printMixingProportions(double m1, double m2, double m3)
{
    std::cout << "\nMixing Proportions:\n";
    std::cout << "  M1 = " << m1 << "\n";
    std::cout << "  M2 = " << m2 << "\n";
    std::cout << "  M3 = " << m3 << "\n";
}

// -----------------------------------------------------------------------------
// Computes and prints the total proportion of each element in the final blend.
// If M1, M2, M3 are correct, all three values should be approximately equal.
// -----------------------------------------------------------------------------
void printBlendComposition(
    double m1, double m2, double m3,
    double n1, double p1, double k1,
    double n2, double p2, double k2,
    double n3, double p3, double k3)
{
    double totalNitrogen   = m1 * n1 + m2 * n2 + m3 * n3;
    double totalPhosphorus = m1 * p1 + m2 * p2 + m3 * p3;
    double totalPotassium  = m1 * k1 + m2 * k2 + m3 * k3;

    std::cout << "\nFinal Blend Composition:\n";
    std::cout << "  Total nitrogen   (N): " << totalNitrogen   << "\n";
    std::cout << "  Total phosphorus (P): " << totalPhosphorus << "\n";
    std::cout << "  Total potassium  (K): " << totalPotassium  << "\n";
}

// -----------------------------------------------------------------------------
// Entry point: orchestrates input, computation, and output.
// -----------------------------------------------------------------------------
int main()
{
    double n1, p1, k1;
    double n2, p2, k2;
    double n3, p3, k3;

    readIngredients(n1, p1, k1, n2, p2, k2, n3, p3, k3);

    double m1 = solveM1(n1, p1, k1, n2, p2, k2, n3, p3, k3);
    double m2 = solveM2(m1, n1, p1, n2, p2, n3, p3);
    double m3 = solveM3(m1, m2);

    printMixingProportions(m1, m2, m3);
    printBlendComposition(
        m1, m2, m3,
        n1, p1, k1,
        n2, p2, k2,
        n3, p3, k3);

    return 0;
}
