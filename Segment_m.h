//
// Generated file, do not edit! Created by nedtool 5.0 from Segment.msg.
//

#ifndef __SEGMENT_M_H
#define __SEGMENT_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>Segment.msg:2</tt> by nedtool.
 * <pre>
 * packet Segment
 * {
 *     int num_seq;
 *     int horloge;
 * }
 * </pre>
 */
class Segment : public ::omnetpp::cPacket
{
  public:
    int num_seq;
    int horloge;

  private:
    void copy(const Segment& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Segment&);

  public:
    Segment(const char *name=nullptr, int kind=0);
    Segment(const Segment& other);
    virtual ~Segment();
    Segment& operator=(const Segment& other);
    virtual Segment *dup() const {return new Segment(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual int getNum_seq() const;
    virtual void setNum_seq(int num_seq);
    virtual int getHorloge() const;
    virtual void setHorloge(int horloge);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Segment& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Segment& obj) {obj.parsimUnpack(b);}


#endif // ifndef __SEGMENT_M_H

