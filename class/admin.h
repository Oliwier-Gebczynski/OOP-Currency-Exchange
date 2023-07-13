#include "main.h"

/**
 * @class Admin
 * @brief A class representing an admin with privileged access.
 */
class Admin {
private:
    std::string const password; ///< Admin password.

public:
    /**
     * @brief Default constructor for the Admin class.
     */
    Admin() : password("czytwysweja") {}

    /**
     * @brief Adds a user to the system.
     * @param user The user object to add.
     */
    void addUser(User user);

    /**
     * @brief Deletes a user from the system.
     * @param ID The ID of the user to delete.
     */
    void deleteUser(int ID);

    /**
     * @brief Modifies the first name of a user.
     * @param ID The ID of the user to modify.
     * @param firstName The new first name.
     */
    void modifyUserFirstName(int ID, std::string firstName);

    /**
     * @brief Modifies the last name of a user.
     * @param ID The ID of the user to modify.
     * @param lastName The new last name.
     */
    void modifyUserLastName(int ID, std::string lastName);

    /**
     * @brief Modifies the email of a user.
     * @param ID The ID of the user to modify.
     * @param email The new email address.
     */
    void modifyUserEmail(int ID, std::string email);

    /**
     * @brief Modifies the password of a user.
     * @param ID The ID of the user to modify.
     * @param password The new password.
     */
    void modifyUserPassword(int ID, std::string password);

    /**
     * @brief Modifies the PIN of a user.
     * @param ID The ID of the user to modify.
     * @param PIN The new PIN number.
     */
    void modifyUserPIN(int ID, int PIN);
};
