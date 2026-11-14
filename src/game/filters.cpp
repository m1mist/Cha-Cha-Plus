// Bloom and depth of field on/off (settings bloom, depth_of_field).
//
// Replaces: uBloomFilter::vf11 @ 0x02A77C44 (inherited by uAppBloomFilter), uDOFFilter::vf11 @ 0x02A84984 and
// uBokehFilter::vf11 @ 0x02A798C8. Status: wip - verified by frame comparison in Moga Village (bloom/DOF passes gone,
// rest of the frame unchanged).
//
// MT Framework's screen effects are units (uFilter : cUnit) with their draw in vtable slot 11 (uFilter::vf11 is an
// empty stub; each filter overrides it with its passes: shader technique, render target, full-screen quad). With an
// effect switched off the draw is skipped, as if the filter had nothing to do this frame; the filters' update and
// their parameters are untouched, so switching back on needs no reset.
#include "filters.h"

#include "functions.h"

#include <atomic>

namespace mh3u::game {
namespace {

std::atomic<bool> g_bloom{true}, g_dof{true};  // the launcher switches them from the host main thread

PPC_FUNC(bloom_draw) {
    if (g_bloom) sub_02A77C44__orig(ctx, base);
}
PPC_FUNC(dof_draw) {
    if (g_dof) sub_02A84984__orig(ctx, base);
}
PPC_FUNC(bokeh_draw) {
    if (g_dof) sub_02A798C8__orig(ctx, base);
}

}  // namespace

void set_filters(bool bloom, bool depth_of_field) {
    g_bloom = bloom;
    g_dof = depth_of_field;
}

void register_filters(bool bloom, bool depth_of_field) {
    set_filters(bloom, depth_of_field);
    ppc::set_override(0x02A77C44, &bloom_draw);
    ppc::set_override(0x02A84984, &dof_draw);
    ppc::set_override(0x02A798C8, &bokeh_draw);
}

}  // namespace mh3u::game
