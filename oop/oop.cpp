#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cassert>

using namespace std;

// Base class AbstractPrinter
class AbstractPrinter {
protected:
    string documentName;

public:
    void setDocumentName(const string& docName) {
        documentName = docName;
    }

    virtual string printDocument() const = 0;
    virtual string scanDocument() const = 0;
    virtual string selectPrinter() const = 0;
    virtual ~AbstractPrinter() {}
};

// Derived class for InkSlinger (small printer)
class InkSlinger : public AbstractPrinter {
public:
    string printDocument() const override {
        return "Printing small document '" + documentName + "' on InkSlinger.";
    }

    string scanDocument() const override {
        return "Scanning small document '" + documentName + "' on InkSlinger.";
    }

    string selectPrinter() const override {
        return "Selecting InkSlinger for small document.";
    }
};

// Derived class for LaserMaster (medium printer)
class LaserMaster : public AbstractPrinter {
public:
    string printDocument() const override {
        return "Printing medium document '" + documentName + "' on LaserMaster.";
    }

    string scanDocument() const override {
        return "Scanning medium document '" + documentName + "' on LaserMaster.";
    }

    string selectPrinter() const override {
        return "Selecting LaserMaster for medium document.";
    }
};

// Derived class for PrintTitan (large printer)
class PrintTitan : public AbstractPrinter {
public:
    string printDocument() const override {
        return "Printing large document '" + documentName + "' on PrintTitan.";
    }

    string scanDocument() const override {
        return "Scanning large document '" + documentName + "' on PrintTitan.";
    }

    string selectPrinter() const override {
        return "Selecting PrintTitan for large document.";
    }
};

// Function to test polymorphism

void testPolymorphism(AbstractPrinter& printer) 
{
    printer.setDocumentName("PolyDoc");
    cout << printer.printDocument() << endl;
    cout << printer.scanDocument() << endl;
    cout << printer.selectPrinter() << endl;
}

void runTests() {
    {
        InkSlinger printer;
        printer.setDocumentName("Doc1");
        assert(printer.printDocument() == "Printing small document 'Doc1' on InkSlinger.");
        assert(printer.scanDocument() == "Scanning small document 'Doc1' on InkSlinger.");
        assert(printer.selectPrinter() == "Selecting InkSlinger for small document.");
    }

    {
        LaserMaster printer;
        printer.setDocumentName("Doc2");
        assert(printer.printDocument() == "Printing medium document 'Doc2' on LaserMaster.");
        assert(printer.scanDocument() == "Scanning medium document 'Doc2' on LaserMaster.");
        assert(printer.selectPrinter() == "Selecting LaserMaster for medium document.");
    }

    {
        PrintTitan printer;
        printer.setDocumentName("Doc3");
        assert(printer.printDocument() == "Printing large document 'Doc3' on PrintTitan.");
        assert(printer.scanDocument() == "Scanning large document 'Doc3' on PrintTitan.");
        assert(printer.selectPrinter() == "Selecting PrintTitan for large document.");
    }

    cout << "All tests passed!" << endl;
}

void handleDocumentPrintingAndScanning() {
    string documentName;
    int documentSize;
    int action;
    char continueInput;

    do {
        cout << "Enter the name of the document: ";
        cin.ignore();
        getline(cin, documentName);

        cout << "Enter the document size (1 for small, 2 for medium, 3 for large): ";
        cin >> documentSize;

        unique_ptr<AbstractPrinter> printer = nullptr;

        switch (documentSize) {
        case 1:
            printer = make_unique<InkSlinger>();
            break;
        case 2:
            printer = make_unique<LaserMaster>();
            break;
        case 3:
            printer = make_unique<PrintTitan>();
            break;
        default:
            cout << "Invalid document size entered." << endl;
            continue;
        }

        printer->setDocumentName(documentName);
        cout << printer->selectPrinter() << endl;

        cout << "Choose an action (1 for print, 2 for scan): ";
        cin >> action;

        switch (action) {
        case 1:
            cout << printer->printDocument() << endl;
            break;
        case 2:
            cout << printer->scanDocument() << endl;
            break;
        default:
            cout << "Invalid action entered." << endl;
            continue;
        }

        cout << "Do you want to enter another document? (y/n): ";
        cin >> continueInput;

    } while (continueInput == 'y');
}

int main() {
    runTests();
    handleDocumentPrintingAndScanning();
    return 0;
}
