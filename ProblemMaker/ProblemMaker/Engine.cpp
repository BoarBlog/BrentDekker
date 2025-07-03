//--------------------------------------------------
// Implementation code for the Engine
//
// @author: Wild Boar
//
// @date: 2025-07-02
//--------------------------------------------------

#include "Engine.h"
using namespace NVL_App;

//--------------------------------------------------
// Constructor and Terminator
//--------------------------------------------------

/**
 * Main Constructor
 * @param logger The logger that we are using for the system
 * @param parameters The input parameters
 */
Engine::Engine(NVLib::Logger* logger, NVLib::Parameters* parameters) 
{
    NVLib::RandomUtils::TimeSeedRandomNumbers();

    _logger = logger; _parameters = parameters;

    _logger->Log(1, "Creating a path helper");
    auto database = ArgUtils::GetString(parameters, "database");
    auto dataset = ArgUtils::GetString(parameters, "dataset");
    _pathHelper = new NVLib::PathHelper(database, dataset);
}

/**
 * Main Terminator 
 */
Engine::~Engine() 
{
    delete _parameters; delete _pathHelper;
}

//--------------------------------------------------
// Execution Entry Point
//--------------------------------------------------

/**
 * Entry point function
 */
void Engine::Run()
{
    auto path = _pathHelper->GetPath("Problems", "problems.xml");

    auto writer = FileStorage(path, FileStorage::WRITE | FileStorage::FORMAT_XML);
    if (!writer.isOpened()) throw runtime_error("Failed to open output file");

    for (auto i = 0; i < 100; i++) 
    {
        writer << "problem" << "{";

        auto roots = HelperUtils::GetRoots(5);
        cout << "Roots: ";
        for (const auto& root : roots) cout << root << " ";
        auto equation = HelperUtils::GetEquation(roots);
        auto polynomial = Polynomial(equation);

        writer << "coeffs" << polynomial.GetCoeffs();

        cout << ": " << equation << " ";
        auto bracket = HelperUtils::GetBracket(&polynomial, roots[1], roots[3], roots[2]);
        cout << "Bracket: [" << bracket[0] << ", " << bracket[1] << "]" << "(" << roots[2] << ")" << endl;

        writer << "bracket" << bracket;

        writer << "root" << roots[2];

        writer << "}";
    }

    writer.release();
}
