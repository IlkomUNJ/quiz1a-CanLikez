#include <iostream>
#include "bank_customer.h"
#include "buyer.h"
#include <string>
#include <vector>
#include "seller.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT, ADMIN_LOGIN};
enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};
using namespace std;

int main() {
    //create a loop prompt 
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;
    const string ADMIN_USERNAME = "root";
    const string ADMIN_PASSWORD = "toor";
    string username, password;  
    vector<BankCustomer> allBankAccounts;
    vector<Buyer> allBuyers;
    vector<seller> allSellers;

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Admin Login" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);
        switch (prompt) {
            case LOGIN:
                cout << "Login selected." << endl;
                /* if Login is selected, based on authority then provide options:
                assume user is logged in as Buyer for now
                1. Chek Account Status (will display if user is Buyer or Seller or both and linked banking account status)
                Will display Buyer, Seller and Banking Account details
                2. Upgrade Account to Seller
                Will prompt user to enter Seller details and create a Seller account linked to Buyer account
                Will reject if a user dont have a banking account linked
                3. Create Banking Account (if not already linked), will be replaced with banking functions
                Must provides: initial deposit amount, Address, Phone number, Email
                Banking functions will provides: Balance checking, Transaction History, Deposit, Withdraw
                4. Browse Store Functionality
                Will display all stores initially
                Need to select a store to browse each store inventory
                Will display all items in the store inventory
                After selecting an item, will display item details and option to add to cart
                After adding to cart, will notify user item is added to cart
                5. Order Functionality
                Will display all items in cart
                Will provide option to remove item from cart
                Will provide option to checkout
                After checkout invoide will be generated (will go to payment functionality)
                6. Payment Functionality
                Will display all listed invoices
                Pick an invoice to pay
                Will display invoice details and total amount
                Will provide option to pay invoice
                Payment is done through confirmation dialogue
                In confirmation dialogue, will display account balance as precursor
                User will need to manually enter invoice id to pay
                After paying balance will be redacted from buyer and added to the responding seller account
                After payment, order status will be changed to paid
                7. Logout (return to main menu)
                Display confirmation dialogue
                If confirmed, return to main menu
                If not, return to Buyer menu
                8. Delete Account (remove both Buyer and Seller account and relevant banking account)
                Display confirmation dialogue
                If confirmed, delete account and return to main menu
                If not, return to Buyer menu

                assume user is logged in as Seller for now
                9. Check Inventory
                10. Add Item to Inventory
                11. Remove Item from Inventory
                12. View Orders (will display all orders placed to this seller
                Only orders with paid status will be listed
                Order details will listing items, quantity, total amount, buyer details, order status (paid, cancelled, completed)
                extra functions
                9. Exit to main Menu
                10. Exit Program
                **/
                break;
            case REGISTER:
                regPrompt = CREATE_BUYER; // reset regPrompt to CREATE_BUYER when entering register menu
                while (regPrompt != BACK){
                    cout << "Register selected. " << endl;
                    cout << "Select an option: " << endl;
                    cout << "1. Create Buyer Account" << endl;
                    cout << "2. Create Seller Account" << endl;
                    cout << "3. Back" << endl;
                    int regChoice;
                    cin >> regChoice;
                    regPrompt = static_cast<RegisterPrompt>(regChoice - 1);
                    switch (regPrompt) {
                        case CREATE_BUYER:
                            cout << "Create Buyer Account selected." << endl;
                            break;
                        case CREATE_SELLER:
                            cout << "Create Seller Account selected." << endl;
                            break;
                        case BACK:
                            cout << "Back selected." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }
                /* if register is selected then went throuhh registration process:
                1. Create a new Buyer Account
                Must provides: Name, Home Address, Phone number, Email
                2. Option to create a Seller Account (will be linked to Buyer account)
                Must Provides 1: Home Address, Phone number, Email
                Must provides 2: Store Name, Store Address, Store Phone number, Store Email
                Must provides 3: initial deposit amount
                After finished immediately logged in as Buyer/Seller
                */
                break;
            case EXIT:
                cout << "Exiting." << endl;
                break;
            case ADMIN_LOGIN:
                /* Prompt for username & password then check the entries with our hard coded features */
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
                    cout << "Admin login successful." << endl;
                    bool adminLogedIn = true;
                    while (adminLogedIn) {
                        cout << "Admin Menu: " << endl;
                        cout << "1. Account Management" << endl;
                        cout << "2. System Report" << endl;
                        cout << "3. Logout" << endl;
                        int adminChoice;
                        cin >> adminChoice;
                        switch (adminChoice) {
                            case 1:
                                cout << "Account Management selected." << endl;
                                cout << "Choose option below: " << endl;
                                cout << "1. View All Buyers/Sellers" << endl;
                                cout << "2. View All details of Buyers/Sellers" << endl;
                                cout << "3. Seek certain buyer/seller based on Name / account Id / address / phone number" << endl;
                                cout << "4. Create new buyer/seller/Bank account" << endl;
                                cout << "5. Remove buyer/seller based on ID (all related info will be deleted)" << endl;
                                int accountManagementChoice;
                                cin >> accountManagementChoice;
                                switch (accountManagementChoice) {
                                    case 1:
                                        cout << "View All Buyers/Sellers selected." << endl;
                                        // choose to display wether its buyer or seller or both
                                        int displayChoice;
                                        cout << "Show which one?\n1. Buyers\n2. Sellers\n3. Both\n";
                                        cin >> displayChoice;
                                        if (displayChoice == 1) {
                                            cout << "List of Buyers:\n";
                                            for (auto& buyer : allBuyers) {
                                                cout << "ID: " << buyer.getId() << ", Name: " << buyer.getName() << endl;
                                            }
                                        } else if (displayChoice == 2) {
                                            cout << "List of Sellers:\n";
                                            for (auto& seller : allSellers) {
                                                cout << "ID: " << seller.getId() << endl;
                                            }
                                        } else if (displayChoice == 3) {
                                            cout << "List of Buyers:\n";
                                            for (auto& buyer : allBuyers) {
                                                cout << "ID: " << buyer.getId() << ", Name: " << buyer.getName() << endl;
                                            }
                                            cout << "List of Sellers:\n";
                                            for (auto& seller : allSellers) {
                                                cout << "ID: " << seller.getId() << ", Store Name: " << endl;
                                            }
                                        } else {
                                            cout << "Invalid option." << endl;
                                        }
                                        
                                        break;
                                    case 2:
                                        cout << "View All details of Buyers/Sellers selected." << endl;
                                        // choose to display wether its buyer or seller or both
                                        int detailDisplayChoice;
                                        cout << "Show which one?\n1. Buyers\n2. Sellers\n";
                                        cin >> detailDisplayChoice;
                                        cout << "----------------------------------\n";
                                        if (detailDisplayChoice == 1) {
                                            cout << "--- Available Buyers ---" << endl;
                                            for (auto& buyer : allBuyers) {
                                                cout << "ID: " << buyer.getId() << ", Name: " << buyer.getName() << endl;
                                            }
                                            cout << "\nEnter the ID of the buyer to see full details: ";
                                            int selectedId;
                                            cin >> selectedId;
                                            bool buyerFound = false;
                                            for (auto& buyer : allBuyers) {
                                                if (buyer.getId() == selectedId) {
                                                    cout << "\n--- Full Details for Buyer ID: " << selectedId << " ---" << endl;
                                                    cout << "ID: " << buyer.getId() << endl;
                                                    cout << "Name: " << buyer.getName() << endl;
                                                    cout << "Account ID: " << buyer.getAccount().getId() << endl;
                                                    cout << "Balance: $" << buyer.getAccount().getBalance() << endl;
                                                    cout << "----------------------------------" << endl;
                                                    
                                                    buyerFound = true;
                                                    break;
                                                }
                                            }
                                            // Jika setelah loop selesai buyer tidak ditemukan
                                            if (!buyerFound) {
                                                cout << "Buyer with ID " << selectedId << " was not found." << endl; 
                                            } 
                                        } else if (detailDisplayChoice == 2){
                                            cout << "--- Available Sellers ---" << endl;
                                            for (auto& seller : allSellers) {
                                                cout << "ID: " << seller.getId() << ", Name: " << seller.getName() << endl;
                                            }
                                            cout << "\nEnter the ID of the seller to see full details: "; 
                                            int selectedId;
                                            cin >> selectedId;
                                            bool sellerFound = false;
                                            for (auto& seller : allSellers) {
                                                if (seller.getId() == selectedId) {
                                                    cout << "\n--- Full Details for Seller ID: " << selectedId << " ---" << endl;
                                                    cout << "ID: " << seller.getId() << endl;
                                                    cout << "Seller Name: " << seller.getName() << endl;
                                                    cout << "Account ID: " << seller.getAccount().getId() << endl;
                                                    cout << "Balance: $" << seller.getAccount().getBalance() << endl;
                                                    cout << "----------------------------------" << endl;
                                                    
                                                    sellerFound = true;
                                                    break;
                                                }
                                            }
                                            // Jika setelah loop selesai seller tidak ditemukan
                                            if (!sellerFound) {
                                                cout << "Seller with ID " << selectedId << " was not found." << endl; 
                                            }                                             
                                        }
                                        break;
                                    case 3: {
                                        cout << "Seek certain buyer/seller based on Name / account Id / address / phone number selected." << endl;
                                        // Implement seek certain buyer/seller features here
                                        cout << "Search in :\n1. Buyers\n2. Sellers\n" << endl;
                                        int searchType;
                                        cin >> searchType;
                                        cout << "Search by:\n1. Name\n2. Account Id\n3. Address\n4. Phone Number" << endl;
                                        int searchBy;
                                        cin >> searchBy;
                                        cout << "Enter search query: ";
                                        string searchQuery;
                                        cin.ignore();
                                        getline(cin, searchQuery);
                                        
                                        cout << "Search Result :" << endl;
                                        if (searchType == 1) {
                                            bool found = false;
                                            for (auto& buyer : allBuyers) {
                                                if ((searchBy == 1 && buyer.getName() == searchQuery) ||
                                                    (searchBy == 2 && to_string(buyer.getAccount().getId()) == searchQuery)
                                                    // (searchBy == 3 && buyer.getAddress() == searchQuery) || belum ada address di pembeli
                                                    // (searchBy == 4 && buyer.getPhoneNumber() == searchQuery)
                                                    ) {
                                                    cout << "Buyer found: ID " << buyer.getId() << ", Name: " << buyer.getName() << endl;
                                                    found = true;
                                                }
                                            }
                                            if (!found) cout << "No matching buyer found.\n";
                                        } else if (searchType == 2) {
                                            bool found = false;
                                            for (auto& seller : allSellers) {
                                                if ((searchBy == 1 && seller.getName() == searchQuery) ||
                                                    (searchBy == 2 && to_string(seller.getAccount().getId()) == searchQuery)
                                                    // (searchBy == 3 && seller.getAddress() == searchQuery) ||
                                                    // (searchBy == 4 && seller.getPhoneNumber() == searchQuery)
                                                    ) {
                                                    cout << "Seller found: ID " << seller.getId() << ", Name: " << seller.getName() << endl;
                                                    found = true;
                                                }
                                            }
                                            if (!found) cout << "No matching seller found.\n";
                                        } else {
                                            cout << "Invalid search type.\n";
                                        }
                                    }
                                        break;
                                    case 4:
                                        cout << "Create new buyer/seller/Bank account selected." << endl;
                                        // Implement create new buyer/seller/bank account features here
                                        break;
                                    case 5:
                                        cout << "Remove buyer/seller based on ID (all related info will be deleted) selected." << endl;
                                        // Implement remove buyer/seller based on ID features here
                                        break;
                                    default:
                                        cout << "Invalid option." << endl;
                                        break;
                                }
                                break;
                            case 2:
                                cout << "System Report selected." << endl;
                                // Implement system report features here
                                break;
                            case 3:
                                cout << "Logging out." << endl;
                                adminLogedIn = false; // exit admin menu loop
                                prompt = LOGIN; // balik menu login
                                break;
                            default:
                                cout << "Invalid option." << endl;
                                break;
                        }
                    }
                } else {
                    cout << "Admin login failed." << endl;
                    prompt = LOGIN; // balik menu login
                };

                break;
                /** After login create a sub prompt that provides the following features
                1. Account Management
                    - View All Buyers, Sellers
                    - View All details of Buyers, Sellers
                    - Seek certain buyer of seller based on Name / account Id / address / phone number
                    - Create new buyer/seller/Bank account
                    - Remove buyer/seller based on ID (all related info will be deleted)
                2. System Report
                    - Total number of Buyers, Sellers
                    - Total number of Banking Accounts
                */
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }

    //BankCustomer customer1(1, "Alice", 1000.0);
    //Buyer buyer1(1, customer1.getName(), customer1);
    return 1;
}