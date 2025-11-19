using System;
using System.Collections.Generic;
using System.Linq;

namespace TestSources
{
    /// <summary>
    /// Tests for CollectionQuerySimplification
    /// </summary>
    public class CollectionQuerySimplificationTest
    {
        // ========== POSITIVE TESTS ==========

        // EMB-ISSUE: CollectionQuerySimplification
        public void ShouldDetectWhereFollowedByAny()
        {
            var list = new List<int> { 1, 2, 3 };
            var result = list.Where(x => x > 1).Any(); // Should trigger
        }

        // EMB-ISSUE: CollectionQuerySimplification
        public void ShouldDetectWhereFollowedByFirst()
        {
            var list = new List<int> { 1, 2, 3 };
            var result = list.Where(x => x > 1).First(); // Should trigger
        }

        // ========== NEGATIVE TESTS ==========

        // EMB-ISSUE: CollectionQuerySimplification/no-detect
        public void ShouldNotDetectDirectAny()
        {
            var list = new List<int> { 1, 2, 3 };
            var result = list.Any(x => x > 1); // Should NOT trigger
        }

        // EMB-ISSUE: CollectionQuerySimplification/no-detect
        public void ShouldNotDetectDirectFirst()
        {
            var list = new List<int> { 1, 2, 3 };
            var result = list.First(x => x > 1); // Should NOT trigger
        }
    }
}
