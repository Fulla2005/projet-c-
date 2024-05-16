int main() {
    Banque banque;

    std::shared_ptr<Compte> compte1 = std::make_shared<Compte>(1, 1000);
    banque.ajouterCompte(compte1);

    std::shared_ptr<Compte> compte2 = std::make_shared<Compte>(2, 500);
    banque.ajouterCompte(compte2);

    std::shared_ptr<Compte> compteRetrouve;
    int id;
    double montant;

    while (true) {
        std::cout << "Choisir une action: 1. Deposer, 2. Retirer, 3. Quitter" << std::endl;
        int action;
        std::cin >> action;

        if (action == 3) {
            break;
        }

        std::cout << "Entrez l'id du compte: ";
        std::cin >> id;

        compteRetrouve = banque.trouverCompte(id);

        if (!compteRetrouve) {
            std::cout << "Compte inexistant." << std::endl;
            continue;
        }

        if (action == 1) {
            std::cout << "Entrez le montant à déposer: ";
            std::cin >> montant;
            compteRetrouve->deposer(montant);
            std::cout << "Le solde du compte " << id << " est maintenant de " << compteRetrouve->getSolde() << "." << std::endl;
        } else if (action == 2) {
            std::cout << "Entrez le montant à retirer: ";
            std::cin >> montant;
            if (compteRetrouve->retirer(montant)) {
                std::cout << "Le solde du compte " << id << " est maintenant de " << compteRetrouve->getSolde() << "." << std::endl;
            } else {
                std::cout << "Solde insuffisant pour effectuer le retrait." << std::endl;
            }
        }
    }

    return 0;
}
