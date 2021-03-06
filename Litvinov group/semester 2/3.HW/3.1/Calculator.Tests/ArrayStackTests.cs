﻿using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace StackCalculator
{
    /// <summary>
    /// Tests for class ArrayStack
    /// </summary>
    [TestClass]
    public class ArrayStackTests
    {
        private IStack stack;

        /// <summary>
        /// Initialize stack
        /// </summary>
        [TestInitialize]
        public void Init()
        {
            stack = new ArrayStack();
        }

        /// <summary>
        /// Try to add and delete element
        /// </summary>
        [TestMethod]
        public void AddAndDeleteElement()
        {
            stack.Push("111");
            stack.Pop();
        }

        /// <summary>
        /// Delete element from the empty stack
        /// </summary>
        [TestMethod]
        public void DeleteElementFromTheEmptyStack()
        {
            stack.Pop();
        }

        /// <summary>
        /// Add and delete some elements, then get size after each method
        /// </summary>
        [TestMethod]
        public void AddAndDeleteSomeElementsGetSizeAfterEachMethod()
        {
            Assert.AreEqual(0, stack.Size());
            stack.Push("1");
            Assert.AreEqual(1, stack.Size());
            stack.Push("1");
            Assert.AreEqual(2, stack.Size());
            stack.Pop();
            Assert.AreEqual(1, stack.Size());
            stack.Pop();
            Assert.AreEqual(0, stack.Size());
        }

        /// <summary>
        /// Add and delete some elements and check IsEmpty after each method
        /// </summary>
        [TestMethod]
        public void AddAndDeleteSomeElementsCheckIsEmptyAfterEachMethod()
        {
            Assert.IsTrue(stack.IsEmpty());
            stack.Push("1");
            Assert.IsFalse(stack.IsEmpty());
            stack.Push("1");
            Assert.IsFalse(stack.IsEmpty());
            stack.Pop();
            Assert.IsFalse(stack.IsEmpty());
            stack.Pop();
            Assert.IsTrue(stack.IsEmpty());
        }

        /// <summary>
        /// Add 1 and 2, shal return 2 and 1
        /// </summary>
        [TestMethod]
        public void Add1And2ShallReturn2And1()
        {
            stack.Push("1");
            stack.Push("2");
            Assert.AreEqual("2", stack.Pop());
            Assert.AreEqual("1", stack.Pop());
        }

        /// <summary>
        /// Check array expansion with twelve elements
        /// </summary>
        [TestMethod]
        public void CheckArrayExpansionWithTwelveElements()
        {
            for (int i = 0; i < 12; ++i)
            {
                stack.Push(Convert.ToString(i, 10));
            }

            Assert.AreEqual(12, stack.Size());

            for (int i = 11; i >= 0; --i)
            {
                Assert.AreEqual(i, int.Parse(stack.Pop()));
            }
        }
    }
}