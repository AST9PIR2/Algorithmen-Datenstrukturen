#include <string>
#include <utility>

class Edge {
    private:
        // string source; beginning of the directed connection
        std::string src;

        // string destination; end of the directed connection
        std::string dest;

        //int distance; beginning to end of the directed connection
        int distance{};

    public:
        Edge(std::string src, std::string dest, int distance){
            this->setSrc(std::move(src));
            this->setDest(std::move(dest));
            this->setDistance(distance);
        };

        ~Edge()= default;

        [[nodiscard]] const std::string& getSrc() const;

        void setSrc(std::string src);

        [[nodiscard]] const std::string& getDest() const;

        void setDest(std::string dest);

        [[nodiscard]] int getDistance() const;

        void setDistance(int distance);
};
