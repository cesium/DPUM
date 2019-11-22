module Tree
  class Node
    getter :children, :content, :level

    def initialize(content : String, level : Int8)
      @children = [] of Tree::Node
      @content = content
      @level = level
    end

    def add_child(child)
      @children << child
    end

    def traverse_subtree(&block)
      node_queue = [self]
      until node_queue.empty?
        node = node_queue.shift
        yield node
        node_queue = node.children.concat(node_queue)
      end
    end
  end
end
