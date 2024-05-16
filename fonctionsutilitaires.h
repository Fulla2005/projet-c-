#include <iostream>
#include <vector>
#include <memory>

class Compte {
public:
    Compte(int id, double solde) : id_(id), solde_(solde) {}
    int getId() const { return id_; }
    double getSolde() const { return solde_; }
    void deposer(double montant) { solde_ += montant; }
    bool retirer(double montant) {
        if (solde_ >= montant) {
            solde_ -= montant;
            return true;
        }
        return false;
    }

private:
    int id_;
    double solde_;
};

class Banque {
public:
    Banque() {}
    void ajouterCompte(std::shared_ptr<Compte> compte) {
        comptes_.push_back(compte);
    }
    std::shared_ptr<Compte> trouverCompte(int id) const {
        for (const auto& compte : comptes_) {
            if (compte->getId() == id) {
                return compte;
            }
        }
        return nullptr;
    }

private:
    std::vector<std::shared_ptr<Compte>> comptes_;
};
