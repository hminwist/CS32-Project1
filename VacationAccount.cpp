
#include "VacationAccount.h"

namespace {
    const int MIN_INTERVAL_DAYS = 180;
    const double HOURS_PER_DONATION = 4.0;
}

VacationAccount::VacationAccount(const std::string& donorId)
    : m_id(donorId), m_items(nullptr), m_size(0), m_capacity(0), m_hours(0.0)
{
    // You may assume donorId is a valid 6-digit employee ID.
    // You do not need to validate it in this constructor.
    // add() will verify that each donation belongs to this account.
}

VacationAccount::~VacationAccount() {
    // TODO: delete owned BloodDonation pointers and array
    for(int i = 0; i < m_size; i ++)
    {
        delete m_items[i]; 
    }
    delete[] m_items; 
}

VacationAccount::VacationAccount(const VacationAccount& other)
    : m_id(other.m_id), m_items(nullptr), m_size(0), m_capacity(0), m_hours(0.0)
{
    // TODO: deep copy other's donations and hours
    m_hours = other.m_hours;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    if(other.m_items != nullptr)
    {
        m_items = new BloodDonation*[m_capacity]; 
        for (int i = 0; i < m_size; i ++)
        {
            BloodDonation* current =  new BloodDonation(*other.m_items[i]);
            m_items[i]= current;
        }
    }
    else
        m_items = nullptr;

}

VacationAccount& VacationAccount::operator=(const VacationAccount& other) {
    if (this != &other) {
        // TODO: release current resources and deep copy from other
        for(int i = 0; i < m_size; i ++)
        {
            delete m_items[i]; 
        }
        delete[] m_items;
        m_hours = other.m_hours;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_id = other.m_id;
        if(other.m_items != nullptr)
        {
            m_items = new BloodDonation*[m_capacity]; 
            for (int i = 0; i < m_size; i ++)
            {
                BloodDonation* current =  new BloodDonation(*other.m_items[i]);
                m_items[i]= current;
            }
        }
        else
            m_items = nullptr;
    }
    return *this;
}

void VacationAccount::ensureCapacity(int need) {
    // TODO: ensure m_items has room for at least 'need' pointers.
    // m_size is the number of donations stored; m_capacity is the number
    // of pointer slots allocated. Any growth strategy that provides at
    // least 'need' slots is acceptable (simple +1 growth is acceptable).
    if (need <= m_capacity)
        return;
    BloodDonation ** newArray = new BloodDonation *[need];
    for (int i = 0; i < m_size; i ++)
    {
        BloodDonation* current =  new BloodDonation(*m_items[i]);
        newArray[i]= current;
    }
    for(int i = 0; i < m_size; i ++)
    {
        delete m_items[i]; 
    }
    delete[] m_items;
    m_items = newArray;
    m_capacity = need;
}

void VacationAccount::clear() {
    // TODO: delete owned donations, delete array, reset fields
    for(int i = 0; i < m_size; i ++)
    {
        delete m_items[i]; 
    }
    delete[] m_items;
    m_items = nullptr;
    m_size = 0;
    m_capacity = 0; 
    m_hours = 0; 
}

void VacationAccount::deepCopyFrom(const VacationAccount& other) {
    // TODO: give this account its own independently allocated array and
    // independently allocated copies of each BloodDonation. Do not merely
    // copy the BloodDonation* pointer values.
    if (this != &other) {
        for(int i = 0; i < m_size; i ++)
        {
            delete m_items[i]; 
        }
        delete[] m_items;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        if(other.m_items != nullptr)
        {
            m_items = new BloodDonation*[m_capacity]; 
            for (int i = 0; i < m_size; i ++)
            {
                BloodDonation* current =  new BloodDonation(*other.m_items[i]);
                m_items[i]= current;
            }
        }
        else
            m_items = nullptr;
    }
}

const std::string& VacationAccount::id() const { return m_id; }
double VacationAccount::balanceHours() const { return m_hours; }
int VacationAccount::size() const { return m_size; }

const BloodDonation* VacationAccount::at(int index) const {
    if (index < 0 || index >= m_size) return nullptr;
    return m_items[index];
}

std::string VacationAccount::add(const BloodDonation& donation) {
    // TODO: Implement in this exact order:
    // 1) Independent validation (donation.validate()). If not OK, return that code.
    // 2) Account ID equality: if donation.id() != m_id, return Result::BAD_ID.
    // 3) SAME_DAY: if any accepted donation has the same calendar date,
    //    return Result::SAME_DAY.
    // 4) TOO_SOON: compare with the most recently accepted donation
    //    (m_items[m_size - 1]). If daysBetween(...) < 180,
    //    return Result::TOO_SOON. Exactly 180 days is allowed.
    //    You may assume donations are submitted in chronological order.
    // 5) On success: store an independent copy, append it to the array,
    //    increment hours by +4.0, and return Result::OK.
    
    std::string validation = donation.validate();
    if(validation != Result::OK)
        return validation;
    if (donation.id() != m_id)
        return Result::BAD_ID;
    if(m_items == nullptr)
    {
        m_capacity = 1; 
        m_size = 0;
        m_items = new BloodDonation*[m_capacity];
        m_items[m_size] = new BloodDonation(donation);
        m_size += 1;
        m_hours += 4;
        return Result::OK;
    }
    else
    {
        BloodDonation* previous = new BloodDonation(*m_items[m_size-1]);
        Date prevDate = previous->date();
        Date currentDate =  donation.date();

        if(DateUtil::sameDay(prevDate, currentDate))
            return Result::SAME_DAY;
        else if(DateUtil::daysBetween(currentDate, prevDate) < 180)
            return Result::TOO_SOON;

        ensureCapacity(m_size + 1);
        m_items[m_size] = new BloodDonation(donation);
        m_size += 1;
        m_hours += 4;
        return Result::OK; 
    }
    
}