

class Game{

  bool m_Quit = false;

  public:
    
    Game(){};
    ~Game();

    void initialise();
    void close();
    void run();
};
