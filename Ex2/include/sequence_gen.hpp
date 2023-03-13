template <typename T>
class SequenceGen
{
public:
    SequenceGen(T start, T step) : m_start(start), m_step(step) {}
    T operator()() { return m_start += m_step; }

private:
    T m_start;
    T m_step;
};