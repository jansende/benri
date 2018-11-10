#pragma once

namespace benri
{
#ifndef BENRI_PRECISION
using Precision = double;
#else
using Precision = BENRI_PRECISION;
#endif
} // namespace benri